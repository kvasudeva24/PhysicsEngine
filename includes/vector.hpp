#pragma once


namespace Physics {

    class vector2d{

        float x;
        float y;


    public:



        friend vector2d& operator+(vector2d& v1, const vector2d& v2);
        friend vector2d& operator+=(vector2d& v1, const vector2d& v2);

        friend vector2d& operator-(vector2d& v1, const vector2d& v2);
        friend vector2d& operator-=(vector2d& v1, const vector2d& v2);
        
        friend vector2d& operator/(vector2d& v1, const vector2d& v2);
        friend vector2d& operator/=(vector2d& v1, const vector2d& v2);

        friend vector2d& operator*(vector2d& v1, const vector2d& v2);
        friend vector2d& operator*=(vector2d& v1, const vector2d& v2);

        friend bool operator==(const vector2d& v1, const vector2d&rhs);
        friend bool operator!=(const vector2d& v1, const vector2d&rhs);

        float magnitude();
        float magnitude_squared();

        vector2d normalize();

        friend float dot_product(const vector2d& v1, const vector2d&rhs);

        float distance_to(const vector2d& other);
        float distance_to_squared(const vector2d& other);

        vector2d getNormal();

        float cross(const vector2d& other);


    };

};