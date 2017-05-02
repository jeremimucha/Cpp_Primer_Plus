#! python3

with open('sumafile_input.txt', 'w') as outfile:
	for i in range(30):
		outfile.write(str.format("{}.{}\n",i,i+1))
