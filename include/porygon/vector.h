#ifndef PORYGON_VECTOR_GUARD
#define PORYGON_VECTOR_GUARD

////////////////////////////////////////////////////////////////////////////////
// Types
////////////////////////////////////////////////////////////////////////////////

typedef struct PorygonVector
{
    float x;
    float y;
    float z;
}
PorygonVector;

////////////////////////////////////////////////////////////////////////////////
// Functions
////////////////////////////////////////////////////////////////////////////////

int           porygon_vector_equals(PorygonVector left, PorygonVector right);
PorygonVector porygon_vector_add(PorygonVector left, PorygonVector right);
PorygonVector porygon_vector_subtract(PorygonVector left, PorygonVector right);
PorygonVector porygon_vector_multiply(PorygonVector left, PorygonVector right);
PorygonVector porygon_vector_divide(PorygonVector left, PorygonVector right);
PorygonVector porygon_vector_negate(PorygonVector vector);
float         porygon_vector_dot(PorygonVector left, PorygonVector right);
PorygonVector porygon_vector_cross(PorygonVector left, PorygonVector right);
float         porygon_vector_magnitude(PorygonVector vector);
PorygonVector porygon_vector_normalized(PorygonVector vector);
float         porygon_vector_distance(PorygonVector left, PorygonVector right);
PorygonVector porygon_vector_rotate(PorygonVector vector, PorygonVector rotation);

#endif // PORYGON_VECTOR_GUARD