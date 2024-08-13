import pygame
import sys
import random
from pygame.locals import *

# Inicializa o pygame
pygame.init()

# Configurações da janela em tela cheia
screen = pygame.display.set_mode((0, 0), pygame.FULLSCREEN)
screen_width, screen_height = screen.get_size()

# Divisão em 2/3 para o tabuleiro e 1/3 para a área de perguntas
board_width = (2 * screen_width) // 3
question_width = screen_width - board_width

cell_size = screen_height // 7  # Ajusta o tamanho da célula com base na altura da tela
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

# Lista de perguntas e respostas
questions = [
    ("Qual é a soma dos ângulos internos de um triângulo?", "180"),
    ("Se um objeto custa R$120 e está com 20 por cento de desconto, quanto você pagaria?", "96"),
    ("Qual é a raiz quadrada de 144?", "12"),
    ("Se um trem viaja a uma velocidade de 80km/h, quanto tempo levaria para percorrer 240 km?", "3"),
    ("Qual é a área de um retângulo com comprimento 10 cm e largura 6 cm?", "60"),
    ("Se um dado justo tem seis lados numerados de 1 a 6, qual é a probabilidade de lançar um número ímpar?", "0,5"),
    ("Calcule o volume de um cubo com arestas de 5 cm.", "125"),
    ("Qual é a fração equivalente a 0,75?(simplificada)", "3/4"),
    ("Se uma pizza é dividida em 8 pedaços iguais e você come 3 pedaços, que fração da pizza você comeu?", "3/8"),
    ("Qual é o perímetro de um quadrado com lados de 7 cm?", "28"),
    ("Se um livro custa R$45 e está com 10 por cento de desconto, quanto você pagaria?", "40,50"),
    ("Qual é o produto de 7 e 9?", "63"),
    ("Qual é o valor de 8 elevado à potência de 2?", "64"),
    ("Qual é a área de um triângulo com base de 8 cm e altura de 5 cm?", "20"),
    ("Qual é a soma dos ângulos internos de um hexágono?", "720"),
    ("Se um número é multiplicado por 5 e o resultado é 45, qual é o número?", "9"),
    ("Qual é o valor de 3/4 × 2/5?", "3/10"),
    ("Se você tem um triângulo com ângulos de 50 graus e 60 graus, qual é a medida do terceiro ângulo?", "70"),
    ("Calcule a área de um círculo com raio de 7 cm (use π≈3,14)?", "153,86"),
    ("Qual é a raiz cúbica de 27?", "3"),
    ("Resolva a equação: 2x−7=9. Qual é o valor de x?", "8"),
]

# Fonte
font = pygame.font.Font(None, 48)

# Posições dos jogadores
player_positions = [0, 0, 0, 0]
turn = 0
waiting_for_answer = False
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
    pygame.draw.rect(screen, board_color, (0, 0, board_width, screen_height))
    for idx, (x, y) in enumerate(positions):
        cell_code = simple_board_colors[idx]
        cell_color = color_mapping.get(cell_code, (255, 255, 255))
        pygame.draw.rect(screen, cell_color, (x * cell_size + margin, y * cell_size + margin,
                                               cell_size - 2 * margin, cell_size - 2 * margin))
        text_surface = font.render(str(idx + 1), True, font_color)
        text_rect = text_surface.get_rect(center=(x * cell_size + cell_size // 2, y * cell_size + cell_size // 2))
        screen.blit(text_surface, text_rect)

# Desenha os jogadores nos setores
def draw_players():
    for i in range(4):
        x, y = positions[player_positions[i]]
        sector_x = (i % 2) * sector_size + (x * cell_size) + margin
        sector_y = (i // 2) * sector_size + (y * cell_size) + margin
        pygame.draw.circle(screen, player_colors[i], (sector_x + sector_size // 2, sector_y + sector_size // 2), sector_size // 4)

# Sorteia um valor e move o jogador
def roll_dice():
    return random.randint(1, 6)

# Reinicia o jogo
def restart():
    global player_positions, turn, waiting_for_answer
    player_positions = [0, 0, 0, 0]
    turn = 0
    waiting_for_answer = False
    screen.fill(bg_color)
    draw_board()
    draw_players()
    pygame.display.update()

# Função para mover o jogador e lidar com as perguntas
def move_player(player_index, dice_value):
    global screen, waiting_for_answer

    current_position = player_positions[player_index]
    new_position = current_position + dice_value

    if new_position > 18:
        new_position = 19

    # Verifica se o jogador caiu em uma casa de pergunta
    cell_code = simple_board_colors[new_position]
    if cell_code in color_mapping and cell_code != "00":
        # Escolhe uma pergunta aleatória
        question, answer = random.choice(questions)

        # Limpa a tela e desenha a pergunta
        screen.fill(bg_color)
        draw_board()
        draw_players()

        # Ajusta o tamanho e posição do retângulo rosa
        pink_rect = pygame.Rect(board_width + 20, 40, question_width - 40, screen_height - 80)
        pygame.draw.rect(screen, (255, 20, 147), pink_rect)

        question_text = font.render(f'Jogador {player_index + 1}: {question}', True, font_color)
        question_rect = question_text.get_rect(topleft=(board_width + 30, 50))  # Ajusta a posição dentro do retângulo rosa
        screen.blit(question_text, question_rect)

        pygame.display.update()

        # Caixa de entrada para a resposta
        input_box = pygame.Rect(board_width + 30, 100, 250, 40)
        answer_text = ''
        typing = True
        waiting_for_answer = True

        while typing:
            for event in pygame.event.get():
                if event.type == QUIT:
                    pygame.quit()
                    sys.exit()
                elif event.type == KEYDOWN:
                    if event.key == K_RETURN:
                        typing = False
                        waiting_for_answer = False
                    elif event.key == K_BACKSPACE:
                        answer_text = answer_text[:-1]
                    else:
                        answer_text += event.unicode

            # Desenha a caixa de entrada e a resposta digitada
            screen.fill(bg_color)
            draw_board()
            draw_players()
            pygame.draw.rect(screen, (255, 20, 147), pink_rect)  # Retângulo rosa fixo
            screen.blit(question_text, question_rect)
            pygame.draw.rect(screen, (0, 0, 0), input_box, 2)
            answer_surface = font.render(answer_text, True, font_color)
            screen.blit(answer_surface, (input_box.x + 5, input_box.y + 5))

            pygame.display.update()

        # Verifica se a resposta está correta e exibe o resultado
        if answer_text == answer:
            result_text = 'Resposta correta! Pode avançar.'
            player_positions[player_index] = new_position
        else:
            result_text = 'Resposta incorreta! Não pode avançar.'

        # Exibe o resultado na área de perguntas
        result_surface = font.render(result_text, True, font_color)
        result_rect = result_surface.get_rect(topleft=(board_width + 30, 150))
        screen.blit(result_surface, result_rect)

        pygame.display.update()

        # Espera 2 segundos antes de continuar
        pygame.time.wait(2000)

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
            if event.key == pygame.K_SPACE and not waiting_for_answer:
                dice_value = roll_dice()
                move_player(turn, dice_value)
                turn = (turn + 1) % 4
                
                screen.fill(bg_color)
                draw_board()
                draw_players()

                dice_text = font.render(f'Dado: {dice_value}', True, font_color)
                screen.blit(dice_text, (board_width + 20, 10))
                current_player_text = font.render(f'Vez: Jogador {turn + 1}', True, font_color)
                screen.blit(current_player_text, (board_width + 20, 50))
                
                pygame.display.update()

            if event.key == pygame.K_r:
                restart()

    pygame.display.update()
