import argparse
import sys
import pycurl
from io import BytesIO

NOT_FOUND 		= "HTTP/1.1 404 Not Found\n"

def getRequest(resource, ip, port):
	"""Realiza un HTTP GET request 

    Argumentos:
    resource 	-- direccion donde se encuentra el recurso
    ip 			-- ip donde se encuentra el recurso
    port 		-- puerto donde se pedira el recurso
    """
	path = ip+":"+port+resource
	
	buffer = BytesIO()
	
	c = pycurl.Curl()
	c.setopt(c.URL, path)
	c.setopt(c.WRITEDATA, buffer)
	c.perform()

	
	return buffer.getvalue().decode('iso-8859-1')

def main():

	global des_num, res_num, u_coef, res_coef, total_var, min_flag, mat
	parser = argparse.ArgumentParser(description="HTTP Client")
	
	parser.add_argument("-u", help="Direccion al recurso http")
	parser.add_argument("-i", "--ip", help="Direccion ip del recurso", default="localhost")
	parser.add_argument("-p", "--port", help="Bandera para maximizar", default="8080")

	args = parser.parse_args()
	resource = args.u
	ip = args.ip
	port = args.port
	
	response = getRequest(resource, ip, port)
	if(not response):
		print(NOT_FOUND)
	else:
		print(response)

main()