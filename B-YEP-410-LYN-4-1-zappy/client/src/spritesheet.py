##
## EPITECH PROJECT, 2021
## src
## File description:
## sprit_sheet
##

from client.src import lib

class SpriteSheet():
	def __init__(self, image):
		self.sheet = image

	def get_image(self, frame, width, height, scale, colour):
		image = lib.pygame.Surface((width, height)).convert_alpha()
		image.blit(self.sheet, (0, 0), (frame * width, 0, width, height))
		image = lib.pygame.transform.scale(image, (width * scale, height * scale))
		image.set_colorkey(colour)

		return image