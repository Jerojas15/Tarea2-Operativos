import argparse
import subprocess
from threading import Thread

def run(file, path):
	p1 = subprocess.Popen([file], stdout=subprocess.PIPE)
	output = p1.communicate()[0]
	print(output)

def main():


	parser = argparse.ArgumentParser(description="Programa para hacer una prueba de Stress")
	
	parser.add_argument("executable", help="Ejecutable a probar")
	parser.add_argument("-n", help="Cantidad de hilos a utilizar")
	parser.add_argument("-u", help="Parametro de ejecutable")
	
	args = parser.parse_args()
	exe = args.executable
	file = "./"+exe
	cant = int(args.n)
	path = args.u
	

	for i in range(cant):
		t = Thread(None,run,None,(file,path))
		t.start()


	
	

main()