_center = [worldsize / 2, worldsize / 2];
{
    _x setDamage (random 1) min 0.99;
    true
} count (_center nearObjects ["House", worldSize]);

{
    _x setDamage (random 1) min 0.99;
    true
} count (_center nearObjects ["Building", worldSize]);