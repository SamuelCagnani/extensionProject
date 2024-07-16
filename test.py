import pygame
import sys
import random

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
    "00", "16", "15", "00", "00", "00",
    "00", "17", "14", "13", "12", "11",
    "00", "18", "00", "00", "00", "10",
    "20", "19", "06", "07", "08", "09",
    "00", "00", "05", "00", "00", "00",
    "00", "00", "04", "03", "02", "01"
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
                player_positions[turn] += dice_value
                if player_positions[turn] >= 19:
                    player_positions[turn] = 19
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
