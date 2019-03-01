//
//  Hello World server in C++
//  Binds REP socket to tcp://*:5555
//  Expects "Hello" from client, replies with "World"
//

#include "defs.pb.h"
#include <chrono>
#include <iostream>
#include <string>
#include <thread>
#include <zmq.hpp>

int main()
{
  //  Prepare our context and socket
  zmq::context_t context(1);
  zmq::socket_t socket(context, ZMQ_REP);
  socket.bind("tcp://*:5555");

  while (true)
  {
    using namespace std::chrono_literals;
    zmq::message_t request;

    //  Wait for next request from client
    socket.recv(&request);
    std::cout << "Received Hello" << std::endl;

    //  Do some 'work'
    std::this_thread::sleep_for(1s);

    //  Send reply back to client
    zmq::message_t reply(5);
    std::memcpy(reply.data(), "World", 5);
    socket.send(reply);
  }
}
