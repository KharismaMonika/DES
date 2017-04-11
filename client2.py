import socket
import sys
import desv4
import desv4c

from desv4 import *
from desv4c import *

while True:
    try:
        # Create a TCP/IP socket
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

        # Connect the socket to the port where the server is listening
        server_address = ('localhost', 11000)
        #print >> sys.stderr, 'connecting to %s port %s' % server_address
        sock.connect(server_address)
        # Send data
        message = raw_input('Faishal : ')
        with open('plain.txt', 'wb') as f:
            data1 = f.write(message)
        execfile("desv4.py")
        with open('hasil.txt', 'rb') as file:
            data2 = file.read()
        print >>sys.stderr, 'sending "%s"' % message
        sock.sendall(data2)
        # Look for the response
        data = sock.recv(150)
        amount_received = 0
        amount_expected = len(data)
        while amount_received < amount_expected:
            with open('terima2.txt', 'wb') as f:
                data3 = f.write(data)
            execfile("desv4c.py")
            with open('dekrip2.txt', 'rb') as file:
                data4 = file.read()
            amount_received += len(data4)
            print >>sys.stderr, 'received "%s"' % data4

    finally:
        sock.close()