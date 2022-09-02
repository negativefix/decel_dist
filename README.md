# Deceleration distance calculator for Space Engine (Game)
A command-line utility to compute the distance needed to decelerate using Torricelli's equation.

# Compilation
`gcc decel_dist.c -lm -o decel_dist`

# Usage
Usage: `decel_dist [a] <current_velocity> <max_speed>` - both the current velocity and max speed are in kilometers


```bash
decel_dist 2843 0.1
# Output: Distance needed to decelerate is 40384820.000000 kilometers

decel_dist -a 2843 0.1
# Output: Distance needed to decelerate is 0.269956 AU
```

# License
This project is available under the MIT license.

