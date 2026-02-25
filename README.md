# 🎱 Kinetic-CPP: Multithreaded Physics Engine

A high-performance 2D particle simulation built in C++. This project simulates "billiard-style" elastic collisions, focusing on clean **Object-Oriented Programming (OOP)** and exploring the complexities of **Multithreaded Systems**.

## 🚀 The Vision
The engine simulates a group of particles (balls) in a fixed-size environment. A "cue ball" or particle is launched into the cluster, causing a kinetic dispersion governed by conservation of momentum and energy.

---

## 🛠 Step-by-Step Implementation Roadmap

### Phase 1: The Mathematical Foundation
Before moving objects, you need a custom math library to handle 2D physics.
* **Vector2 Class:** Implement a class to handle `x` and `y` coordinates.
* **Operator Overloading:** Overload `+`, `-`, `*`, and `/` to allow for clean syntax like `position += velocity * dt`.
* **Core Methods:** Implement `dotProduct()`, `magnitude()`, and `normalize()`.

### Phase 2: The Particle Entity (OOP)
Define what a "ball" is in your world.
* **State:** Create a `Particle` class with properties: `position`, `velocity`, `acceleration`, `mass`, and `radius`.
* **Integration:** Use **Euler Integration** to update motion:
    
    $$v_{new} = v_{old} + (a \cdot \Delta t)$$
    $$p_{new} = p_{old} + (v_{new} \cdot \Delta t)$$
* **Boundary Logic:** Check if the particle hits the "table" edges. If it does, invert the velocity (e.g., `velocity.x *= -1`).

### Phase 3: Collision Detection & Resolution
This is the heart of the engine.
1.  **Detection:** Two circles collide if the distance between their centers is less than the sum of their radii.
    
2.  **Static Resolution:** If balls overlap, move them apart along the collision normal so they don't get "stuck" inside each other.
3.  **Dynamic Resolution (Impulse):** Calculate the exchange of momentum.
    * Find the **Collision Normal** (unit vector between centers).
    * Calculate the **Relative Velocity**.
    * Apply the **Impulse Scalar** to update velocities based on mass.

### Phase 4: Parallelization (The "Level Up")
To scale the engine, we introduce `std::thread`.
* **The Strategy:** Divide the total pool of particles into chunks (e.g., Thread A handles particles 0–50, Thread B handles 51–100).
* **Data Synchronization:** Use `std::mutex` or **Double Buffering** (reading from one state while writing to another) to prevent race conditions.
* **Performance Note:** > **Acknowledge:** While multithreading is implemented here to learn parallelization patterns, for small numbers of particles