#ifndef VECTOR_H
#define VECTOR_H

#include <Arduino.h>

class Vector {
    private:
        double x, y;
    public:
        /**
         * Default constructor. Default vector has coordinates (0, 0)
         */
        Vector();
        /**
         * Constructor with named parameters
         * @param x x coordinate
         * @param y y coordinate
         */
        Vector(double x, double y);
        Vector(const Vector &copy);
        Vector operator+(const Vector &);
        Vector operator-(const Vector &);
        Vector operator*(const double k);
        Vector &operator*=(const double k);
        Vector &operator+=(const Vector &);
        Vector &operator=(const Vector &);
        /**
         * Compute the scalar product of two vectors.
         * @example @code
         * Vector v1(1, 2);
         * Vector v2(2, 3);
         * double scalar = v1.scalar(v2); // returns 8.0
         * @endcode
         * @param other the other Vector to do the product with.
         * @return the result of the scalar product
         */
        inline double scalar(const Vector &other) const;

        /**
         * Create and return the normal vector to this vector.
         * The new vector is normal in trigonometrical direction.
         * @example @code
         * Vector v1(1, 2);
         * Vector v2(v1.normal());
         * // v2 now has coordinates (-2, 1) @endcode
         * @return a new Vector which is normal to this vector
         */
        inline Vector normal() const;

        /**
         * Compute and return the angle between this vector and another.
         * @example @code
         * Vector v1(1, 2), v2(-2, 1);
         * double angle = v1.angle_with(v2);
         * // angle now has value 1.570, which pi / 2 @endcode
         * @param other the other vector to calculate the angle with
         * @return the angle between this vector and the other
         */
        double angle_with(const Vector &other) const;

        /**
         * Compute and return the norm of the vector
         * @example @code
         * double norm = Vector(1, 2).norm();
         * // norm has value 2.236 @endcode
         * @return the norm of the vector
         */
        double get_norm() const;
        inline double get_x() const;
        inline double get_y() const;

        /**
         * Create and return a string to print the coordinates of the vector.
         * The returned string contains no carriage return
         * @example @code
         * Vector vec(3, 5);
         * Serial.println(vec.to_string()) @endcode
         * Will print "(3, 5)" in the Serial
         */
        String to_string();
};

Vector operator*(const double k, const Vector &vector);


#endif