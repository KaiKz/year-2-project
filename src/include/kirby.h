#ifndef kirby_H
#define kirby_H

#include "ofMain.h"

using namespace glm;

class kirby
{
public:
    kirby();
    ~kirby();
    // class function members

    /** tell the kirby to update itself
     * Note - classes don't need an update function
     * but we have one here to follow the update-draw 
     * 'programming pattern' in openframeworks 
    */
    void update();
    /** tell the kirby to draw itself */
    void draw();
    void setPosition(float x, float y, float z);
    // end of class function members
private:
// data members
    float xPos;
    float yPos;
    float zPos;
    ofSpherePrimitive body;
    ofSpherePrimitive hand1;
    ofSpherePrimitive hand2;
    ofSpherePrimitive foot1;
    ofSpherePrimitive foot2;
    ofConePrimitive hat;
    
    ofMaterial handMaterial;
    ofMaterial feetMaterial;
    
    ofImage face;
    ofImage cone;
    

};

#endif // TABLE_H
