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

PorygonVector porygon_vector_clamp(PorygonVector vector, PorygonVector min, PorygonVector max)
{
    if (vector.x < min.x)
    {
        vector.x = min.x;
    }
    else if (vector.x > max.x)
    {
        vector.x = max.x;
    }

    if (vector.y < min.y)
    {
        vector.y = min.y;
    }
    else if (vector.y > max.y)
    {
        vector.y = max.y;
    }

    if (vector.z < min.z)
    {
        vector.z = min.z;
    }
    else if (vector.z > max.z)
    {
        vector.z = max.z;
    }

    return vector;
}

PorygonVector porygon_vector_wrap(PorygonVector vector, PorygonVector min, PorygonVector max)
{
    PorygonVector result =
    {
        min.x + fmodf(vector.x - min.x, max.x - min.x),
        min.y + fmodf(vector.y - min.y, max.y - min.y),
        min.z + fmodf(vector.z - min.z, max.z - min.z)
    };
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
    if (rotation.x)
    {
        float pitch_sin = sinf(rotation.x);
        float pitch_cos = cosf(rotation.x);
        vector = (PorygonVector)
        {
            vector.x,
            vector.y * pitch_cos - vector.z * pitch_sin,
            vector.y * pitch_sin + vector.z * pitch_cos
        };
    }

    if (rotation.y)
    {
        float yaw_sin = sinf(rotation.y);
        float yaw_cos = cosf(rotation.y);
        vector = (PorygonVector)
        {
            vector.x * yaw_cos + vector.z * yaw_sin,
            vector.y,
            vector.z * yaw_cos - vector.x * yaw_sin
        };
    }

    if (rotation.z)
    {
        float roll_sin = sinf(rotation.z);
        float roll_cos = cosf(rotation.z);
        vector = (PorygonVector)
        {
            vector.x * roll_cos - vector.y * roll_sin,
            vector.x * roll_sin + vector.y * roll_cos,
            vector.z
        };
    }

    return vector;
}