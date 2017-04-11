import socket
import sys
import desv4s
import desv4k

from desv4s import *
from desv4k import *

server_address = ('', 11000)
print >> sys.stderr, 'starting up on %s port %s' % server_address

# Listen for incoming connections
while True:
    # Create a TCP/IP socket
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

    sock.bind(server_address)
    sock.listen(1)

    # Wait for a connection
    # print >>sys.stderr, 'waiting for a connection'
    connection, client_address = sock.accept()

    try:
        print >>sys.stderr, 'connection from', client_address
        # Receive the data in small chunks and retransmit it
        while True:
            data = connection.recv(150)
            with open('terima.txt', 'wb') as f:
                data1 = f.write(data)
            execfile("desv4s.py")
            with open('dekrip.txt', 'rb') as file:
                data2 = file.read()
            print >>sys.stderr, 'received "%s"' % data2
            if data2:
                message = raw_input('Risma : ')
                with open('kirim.txt', 'wb') as f:
                    data3 = f.write(message)
                execfile("desv4k.py")
                with open('kirimen.txt', 'rb') as file:
                    data4 = file.read()
                print >> sys.stderr, 'sending "%s"' % message
                #print >>sys.stderr, 'sending data back to the client'
                connection.sendall(data4)
            else:
                print >>sys.stderr, 'no more data from', client_address
            break
    finally:
        # Clean up the connection
        connection.close()