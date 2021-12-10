
from client.src import lib

def sound_change(change):
    if lib.mute: lib.pygame.mixer.music.set_volume(0)
    else: lib.pygame.mixer.music.set_volume(1)
    if change != lib.music_state: lib.music_state = 0
    if lib.music_state == 0:
        lib.pygame.mixer.music.stop()
        if (change == 1):
            lib.music_state = 1
            lib.pygame.mixer.music.load("client/sound/elevator_sound.ogg")
            lib.pygame.mixer.music.play(-1)
        if (change == 2):
            lib.music_state = 2
            lib.pygame.mixer.music.load("client/sound/game_sound.ogg")
            lib.pygame.mixer.music.play(-1)