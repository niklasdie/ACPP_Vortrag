#include <memory>
#include "aufgabe.h"

int main() {
    std::unique_ptr test = std::make_unique<int>(5);
    std::shared_ptr test2 = std::make_shared<int>(10);
}