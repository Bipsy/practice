import random
random.seed()

with open("input.txt", "w") as f:
	for i in range(0, 1000):
		mode = random.randint(0, 5)
		acc_num = random.randint(0, 200)
		amount = random.randint(0, 1000)
		command = None
		if mode == 0:
			command = "fee"
		elif mode == 1:
			command = "wd"
		else:
			command = "dep"
		f.write(command + " " + str(acc_num) + " " + str(amount) + '\n')
	f.write("print")