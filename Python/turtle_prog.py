import turtle

def draw_triangle(side_length, depth):
	if depth == 0:
		return
	counter = 0
	while counter < 3:
		counter += 1
		brad.forward(side_length/2)
		if depth > 1:
			brad.left(120)
		draw_triangle(side_length/2, depth-1)
		brad.forward(side_length/2)
		brad.right(120)
	brad.left(240)

if __name__ == "__main__":
	window = turtle.Screen()
	window.bgcolor("white")

	brad = turtle.Turtle()
	brad.shape("turtle")
	brad.color("green", "green")
	brad.speed(5)

	brad.begin_fill()
	brad.right(120)
	brad.forward(128)
	brad.left(120)
	brad.forward(256)
	brad.left(120)
	brad.forward(256)
	brad.left(120)
	brad.forward(128)
	brad.left(120)
	brad.end_fill()
	brad.color("green", "white")
	brad.begin_fill()
	draw_triangle(128, 3)
	brad.end_fill()

	window.exitonclick()
