import zmq
from pynput.keyboard import Listener, Key

context = zmq.Context()
sub_socket = context.socket(zmq.SUB)
sub_socket.bind('tcp://127.0.0.1:4242')
sub_socket.subscribe('')
pub_socket = context.socket(zmq.PUB)
pub_socket.bind('tcp://127.0.0.1:4243')

kill_socket_addr = 'inproc://kill_socket'
kill_socket = context.socket(zmq.PAIR)
kill_socket.bind(kill_socket_addr)

poller = zmq.Poller()
poller.register(sub_socket)
poller.register(kill_socket)

def send_command(key, is_pressed):
    if hasattr(key, 'char'):
        if key.char is None:
            print(key)
            return

        if key.char in 'qweasd':
            cmd = '{} {}'.format(key.char, int(is_pressed))

            global pub_socket
            pub_socket.send(cmd.encode())

key_state = dict()

def on_press(key):
    global key_state

    if key == Key.esc:
        global context
        socket = context.socket(zmq.PAIR)
        socket.connect(kill_socket_addr)
        socket.send(b'')

        return False

    if key not in key_state:
        key_state[key] = False
    
    if not key_state[key]:
        key_state[key] = True

        send_command(key, True)

def on_release(key):
    global key_state
    key_state[key] = False

    send_command(key, False)

listener = Listener(on_press=on_press, on_release=on_release)
listener.start()

print('Keyboard listener started.')
print('Pres W, A, S, D, E, Q to control the character.')
print('Press Esc to exit.')

while True:
    try:
        sockets = dict(poller.poll())
    except zmq.ZMQError:
        break  # interrupted

    if kill_socket in sockets:
        break

    if sub_socket in sockets:
        print(sub_socket.recv_multipart())
