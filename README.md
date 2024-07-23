import pygame
import sys
import random
from pygame.locals import *

# Inicializa o pygame
pygame.init()

# Configurações da janela
width, height = 600, 600
expanded_width = width + 300
expanded_height = height + 300

cell_size = 100
margin = 5
sector_size = (cell_size - margin) // 2

# Cores
bg_color = (255, 255, 255)
board_color = (0, 0, 0)
player_colors = [(255, 0, 0), (0, 255, 0), (0, 0, 255), (255, 255, 0)]
font_color = (0, 0, 0)

# Mapeamento das cores
color_mapping = {
    "16": (240, 230, 140),
    "15": (135, 206, 235),
    "17": (135, 206, 235),
    "14": (135, 206, 235),
    "13": (218, 112, 214),
    "12": (240, 230, 140),
    "11": (135, 206, 235),
    "18": (240, 230, 140),
    "10": (218, 112, 214),
    "20": (176, 196, 222),
    "19": (135, 206, 235),
    "06": (135, 206, 235),
    "07": (218, 112, 214),
    "08": (135, 206, 235),
    "09": (240, 230, 140),
    "05": (240, 230, 140),
    "04": (218, 112, 214),
    "03": (240, 230, 140),
    "02": (135, 206, 235),
    "01": (176, 196, 222),
    "00": (255, 255, 255),  # Cor para células vazias
}

# Cartas com perguntas e respostas
questions = {
    "16": ("Quanto é 2 + 2?", "4"),
    "15": ("Quanto é 3 * 5?", "15"),
    "17": ("Quanto é 4 + 3?", "7"),
    "14": ("Quanto é 5 - 2?", "3"),
    "13": ("Quanto é 6 * 2?", "12"),
    "12": ("Quanto é 7 - 3?", "4"),
    "11": ("Quanto é 8 / 2?", "4"),
    "18": ("Quanto é 9 - 5?", "4"),
    "10": ("Quanto é 10 / 2?", "5"),
    "20": ("Quanto é 11 - 4?", "7"),
    "19": ("Quanto é 12 / 3?", "4"),
    "06": ("Quanto é 13 - 6?", "7"),
    "07": ("Quanto é 14 / 2?", "7"),
    "08": ("Quanto é 15 - 8?", "7"),
    "09": ("Quanto é 16 / 4?", "4"),
    "05": ("Quanto é 17 - 8?", "9"),
    "04": ("Quanto é 18 / 2?", "9"),
    "03": ("Quanto é 19 - 8?", "11"),
    "02": ("Quanto é 20 / 2?", "10"),
    "01": ("Quanto é 21 - 10?", "11"),
    "00": ("Quanto é 22 - 11?", "11"),
}

# Configura a janela
screen = pygame.display.set_mode((expanded_width, expanded_height))
pygame.display.set_caption('Jogo de Tabuleiro')
screen.fill(bg_color)

# Fonte
font = pygame.font.Font(None, 48)

# Posições dos jogadores
player_positions = [0, 0, 0, 0]
turn = 0
positions = [
    (5, 5), (4, 5), (3, 5), (2, 5), (2, 4),
    (2, 3), (3, 3), (4, 3), (5, 3), (5, 2),
    (5, 1), (4, 1), (3, 1), (2, 1), (2, 0),
    (1, 0), (1, 1), (1, 2), (1, 3), (0, 3)
]

# Identificadores das casas
simple_board_colors = [
    "00", "16", "15", "17", "14", "13",
    "12", "11", "18", "10", "20", "19",
    "06", "07", "08", "09", "05", "04",
    "03", "02", "01"
]

# Desenha o tabuleiro
def draw_board():
    pygame.draw.rect(screen, board_color, (150, 150, width + 40, height + 40))

    for idx, (x, y) in enumerate(positions):
        cell_code = simple_board_colors[idx]
        cell_color = color_mapping.get(cell_code, (255, 255, 255))

        pygame.draw.rect(screen, cell_color, (x * cell_size + margin + 150, y * cell_size + margin + 150,
                                               cell_size - 2 * margin, cell_size - 2 * margin))

        # Desenha o número da célula
        text_surface = font.render(str(idx + 1), True, font_color)
        text_rect = text_surface.get_rect(center=(x * cell_size + cell_size // 2 + 150, y * cell_size + cell_size // 2 + 150))
        screen.blit(text_surface, text_rect)

# Desenha os jogadores nos setores
def draw_players():
    for i in range(4):
        x, y = positions[player_positions[i]]
        sector_x = (i % 2) * sector_size + (x * cell_size) + margin + 150
        sector_y = (i // 2) * sector_size + (y * cell_size) + margin + 150
        pygame.draw.circle(screen, player_colors[i], (sector_x + sector_size // 2, sector_y + sector_size // 2), sector_size // 4)

# Sorteia um valor e move o jogador
def roll_dice():
    return random.randint(1, 6)

# Reinicia o jogo
def restart():
    global player_positions, turn
    player_positions = [0, 0, 0, 0]
    turn = 0
    screen.fill(bg_color)
    draw_board()
    draw_players()
    pygame.display.update()

# Função para mover o jogador e lidar com as perguntas
def move_player(player_index, dice_value):
    global screen

    current_position = player_positions[player_index]
    new_position = current_position + dice_value

    if new_position > 18:
        new_position = 19

    # Verifica se o jogador caiu em uma casa de pergunta
    cell_code = simple_board_colors[new_position]
    if cell_code in questions:
        # Escolhe a pergunta da célula
        question, answer = questions[cell_code]

        # Limpa a tela e desenha a pergunta
        screen.fill(bg_color)
        draw_board()
        draw_players()

        question_text = font.render(f'Jogador {player_index + 1}: {question}', True, font_color)
        question_rect = question_text.get_rect(center=(expanded_width // 2, 50))
        screen.blit(question_text, question_rect)

        pygame.display.update()

        # Caixa de entrada para a resposta
        input_box = pygame.Rect(150, 100, 400, 40)
        answer_text = ''
        typing = True

        while typing:
            for event in pygame.event.get():
                if event.type == QUIT:
                    pygame.quit()
                    sys.exit()
                elif event.type == KEYDOWN:
                    if event.key == K_RETURN:
                        typing = False
                    elif event.key == K_BACKSPACE:
                        answer_text = answer_text[:-1]
                    else:
                        answer_text += event.unicode

            # Desenha a caixa de entrada e a resposta digitada
            pygame.draw.rect(screen, (255, 255, 255), input_box, 2)
            answer_surface = font.render(answer_text, True, font_color)
            screen.blit(answer_surface, (input_box.x + 5, input_box.y + 5))

            pygame.display.update()

        # Verifica se a resposta está correta
        if answer_text == answer:
            print('Resposta correta! Pode avançar.')
            player_positions[player_index] = new_position
        else:
            print('Resposta incorreta! Não pode avançar.')

    else:
        # Movimento normal
        player_positions[player_index] = new_position

    return True

draw_board()
draw_players()

# Loop principal do jogo
while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()

        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_SPACE and all(pos < 19 for pos in player_positions):
                dice_value = roll_dice()

                # Verifica se o jogador pode avançar
                move_player(turn, dice_value)
                turn = (turn + 1) % 4
                
                screen.fill(bg_color)
                draw_board()
                draw_players()

                dice_text = font.render(f'Dado: {dice_value}', True, font_color)
                screen.blit(dice_text, (10, 10))
                current_player_text = font.render(f'Vez: Jogador {turn + 1}', True, font_color)
                screen.blit(current_player_text, (10, 50))
                
                pygame.display.update()

            if event.key == pygame.K_r:
                restart()

    pygame.display.update()
