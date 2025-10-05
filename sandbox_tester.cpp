#include <iostream>
#include <fstream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>


void testFilesystemAccess() {
    std::ofstream file("sandbox_test.txt");
    
    if (!file) {  // Check if file opening failed
        std::cerr << "[⛔] File write failed: Sandbox restriction enforced. ("
        << strerror(errno) << " - errno: " << errno << ")\n";
        return;
    }

    file << "Attempting to write inside the sandbox." << std::endl;
    file.close();
    std::cout << "[✅] File write succeeded!\n";
}

void testNetworkAccess() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        std::cerr << "[⛔] Network access blocked by sandbox.\n";
        return;
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(80);
    inet_pton(AF_INET, "23.215.0.136", &server.sin_addr); // example.com

    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
        std::cerr << "[⛔] Connection failed: Sandbox restriction enforced.\n";
    } else {
        std::cout << "[✅] Network connection succeeded!\n";
    }
    close(sock);
}


int main() {
    std::cout << "🔒 macOS App Sandbox Test\n";

    testFilesystemAccess();
    testNetworkAccess();
    
    return 0;
}
