#include "wall.h"

wall::wall()
{
    //ctor
}

int block::render(databank* db)
{
    std::cout << "rendering" << std::endl;
}

int block::init(databank* db)
{
    db->subscribeEvent([this](databank* db)
    {
    this->render(db);
    });

    std::cout << "dll wall here";
}

wall::~wall()
{
    //dtor
}
