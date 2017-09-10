import argparse
import subprocess
from threading import Thread

def run(file, ip, port, rec):
	param = file+ip+rec+port
	args = param.split(" ")
	p1 = subprocess.Popen(args)

def main():


	parser = argparse.ArgumentParser(description="Programa para hacer una prueba de Stress")
	
	parser.add_argument("executable", help="Ejecutable a probar")
	parser.add_argument("-n", help="Cantidad de hilos a utilizar")
	parser.add_argument("-u", help="recurso de ejecutable")
	parser.add_argument("-i", help="ip del socket del ejecutable")
	parser.add_argument("-p", help="puerto del ejecutable")
	
	args = parser.parse_args()
	exe = args.executable
	file = "./"+exe
	cant = int(args.n)
	ip = " -i"+args.i
	port = " -p"+ args.p
	rec = " -u"+args.u
	for i in range(cant):
		t = Thread(None,run,None,(file,ip,port,rec))
		t.start()


	
	

main()