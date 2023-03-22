import socket

"""
def server(host = 'localhsot', port = 7000):
    data_payload = 2048

    # Cria uma Socket TCP 
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # Permite reutilizar o enereço/porta
    sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

    # Une a socket a porta 
    server_address = (host, port)

    print ("Starting up echo server  on %s port %s" % server_address)

    sock.bind(server_address)

    # Escuta os clientes, argumeto especifica o número máximo de conexões na fila
    sock.listen(5)

    i = 0

    while True:
        print("Esperando para receber a mensagem do cliente")

        client, address = sock.accept()
        data = client.recv(data_payload)
        if data:
            print("Data: %s" %data)
            client.send(data)
            print("Enviou %s bytes de volta para %s"%(data, address))
            # Encerra conexão 
            client.close()
            # Executa apenas três vezes 
            i+=1
            if i>=3: break

server()

"""

import socket 
host = '700' 
port = 7000 
addr = (host, port) 
serv_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
serv_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1) 
serv_socket.bind(addr) 
serv_socket.listen(10) 
print ('aguardando conexao') 
con, cliente = serv_socket.accept() 
print ('conectado') 
print ("aguardando mensagem") 
recebe = con.recv(1024) 
print ("mensagem recebida: " + recebe )
serv_socket.close() 