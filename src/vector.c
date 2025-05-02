////////////////////////////////////////////////////////////////////////////////
// Dependencies
////////////////////////////////////////////////////////////////////////////////

#include <porygon/vector.h>

#include <math.h>

////////////////////////////////////////////////////////////////////////////////
// Functions <porygon/vector.h>
////////////////////////////////////////////////////////////////////////////////

int porygon_vector_equals(PorygonVector left, PorygonVector right)
{
    int result = left.x == right.x && left.y == right.y && left.z == right.z;
    return result;
}

PorygonVector porygon_vector_add(PorygonVector left, PorygonVector right)
{
    PorygonVector result =
    {
        left.x + right.x,
        left.y + right.y,
        left.z + right.z
    };
    return result;
}

PorygonVector porygon_vector_subtract(PorygonVector left, PorygonVector right)
{
    PorygonVector result =
    {
        left.x - right.x,
        left.y - right.y,
        left.z - right.z
    };
    return result;
}

PorygonVector porygon_vector_multiply(PorygonVector left, PorygonVector right)
{
    PorygonVector result =
    {
        left.x * right.x,
        left.y * right.y,
        left.z * right.z
    };
    return result;
}

PorygonVector porygon_vector_divide(PorygonVector left, PorygonVector right)
{
    PorygonVector result =
    {
        left.x / right.x,
        left.y / right.y,
        left.z / right.z
    };
    return result;
}

PorygonVector porygon_vector_negate(PorygonVector vector)
{
    PorygonVector result =
    {
        -vector.x,
        -vector.y,
        -vector.z
    };
    return result;
}

float porygon_vector_dot(PorygonVector left, PorygonVector right)
{
    float result = left.x * right.x + left.y * right.y + left.z * right.z;
    return result;
}

PorygonVector porygon_vector_cross(PorygonVector left, PorygonVector right)
{
    PorygonVector result =
    {
        left.y * right.z - left.z * right.y,
        left.z * right.x - left.x * right.z,
        left.x * right.y - left.y * right.x
    };
    return result;
}

float porygon_vector_magnitude(PorygonVector vector)
{
    float result = sqrtf(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
    return result;
}

PorygonVector porygon_vector_normalized(PorygonVector vector)
{
    float length = porygon_vector_magnitude(vector);
    float inverse_length = 1.0f / length;
    PorygonVector result = porygon_vector_multiply(vector, (PorygonVector) { inverse_length, inverse_length, inverse_length });
    return result;
}

float porygon_vector_distance(PorygonVector left, PorygonVector right)
{
    PorygonVector displacement = porygon_vector_subtract(right, left);
    float result = porygon_vector_magnitude(displacement);
    return result;
}

PorygonVector porygon_vector_rotate(PorygonVector vector, PorygonVector rotation)
{
    // todo
}