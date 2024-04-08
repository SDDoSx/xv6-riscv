#include "kernel/types.h"
#include "user/user.h"

uint64 hextoint(const char *hex) {
    uint64 result = 0;
    while (*hex) {
        result = result << 4;
        if (*hex >= '0' && *hex <= '9') {
            result += *hex - '0';
        } else if (*hex >= 'a' && *hex <= 'f') {
            result += *hex - 'a' + 10;
        } else if (*hex >= 'A' && *hex <= 'F') {
            result += *hex - 'A' + 10;
        }
        hex++;
    }
    return result;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(2, "Usage: %s <virtual address in hex>\n", argv[0]);
        exit(1);
    }

    uint64 va = hextoint(argv[1]);
    printf("Testing myV2p for virtual address: 0x%lx\n", va);


    int pa = myV2p(va);
    if (pa < 0) {
        printf("myV2p failed to translate the address 0x%lx.\n", va);
    } else {
        printf("Physical address: 0x%lx\n", pa);
    }

    exit(0);
}
