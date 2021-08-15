#include"class_BaseObject.h"
#include"class_StaticObject.h"
#include"class_DynamicObject.h"
#include"class_Tree.h"
#include"class_House.h"
#include"class_Motorbike.h"
#include"class_Car.h"
#include<vector>
using namespace std;
int main() {
   
    vector<BaseObject*> listObj = vector<BaseObject*>();

    BaseObject* tree = new Tree(101, "Tree: Orange", Position(1.1, 1.1));

    BaseObject* house = new House(201, "House: Villa", Position(2.2, 2.2));

    BaseObject* motorbike = new Motorbike(301, "Motorbike: Wave-a", Position(3.3, 3.3));

    BaseObject* car = new Car(401, "Car: Vinfast", Position(4.4, 4.4));

    listObj.push_back(tree);
    listObj.push_back(house);
    listObj.push_back(motorbike);
    listObj.push_back(car);

    for (auto obj : listObj) {
        cout << obj->getName() <<" - ";
        obj->printPosition();
    }
    cout << endl;
    for (auto obj : listObj) {
        Position pos(1.1, 1.1);
        obj->move(pos);
    }
    cout<<endl<<"New Position After Move Position(1.1, 1.1): " << endl;
    for (auto obj : listObj) {
        obj->printPosition();
    }
    delete tree;
    delete house;
    delete motorbike;
    delete car;
    listObj.clear();
    return 0;

}