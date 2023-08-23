#include <ducks.hpp>

int main() {
    using namespace DuckUSim;

    std::unique_ptr<Duck> duck = std::make_unique<MallardDuck>();
    duck->fly();
    duck->swim();
    duck->quack();

    duck = std::make_unique<ModelDuck>();
    duck->fly();
    duck->swim();
    duck->quack();

    return 0;
}
