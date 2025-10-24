# Image Filtering
- Useful for preprocessing images and generally speaking for removing noise.
- Linear and Non-Linear filters exist.
- A linear filter implemented as convolution is also called LSIS (Linear Shift Invariant System).
- LSIS <=> Convolution.
- Using filters in OpenCV usually means to specify also what to do with the non-existing pixels belonging to the borders. Two common approaches are:
    - replicating the borders by assigning the non existing pixels the same values of neighbour pixels.
    - assume a constant border by assigning a specific value (for example 0).

<br><br>
## Gaussian Blur (fuzzy filter)
Easy to implement, it assigns greater weights to closer pixels following Gaussian distribution.
#### Pros:
- Noise reduction
- Fast
- Smoothing*
#### Cons:
- Non-Edge preservation
- Smoothing*
- Bad against "Salt and Pepper" (noise with values equal to 0 or 255 only) noise
#### Notes:
- Linear

<br><br>
## Median
Assigns the median value of the k<sup>2</sup> considered pixels to the central one.
#### Pros:
- Noise reduction
- Effective against "Salt and Pepper" noise
- Fast
- Smoothing*
#### Cons:
- Non-Edge preservation
- Smoothing*
- Large filters blur the image details
#### Notes:
- Non-linear
- To keep the radius small

<br><br>
## Bilateral Filter
This is basically a fuzzy filter, BUT when computing a value for the central pixel it assign a greater weight to the pixels with similar intensity. In this way the edges are preserved.
#### Pros:
- Great against gaussian noise (most common noise in real world)
- Edge preservation
- Smoothing*
#### Cons:
- Slow (multiple Gaussians are needed)
- Smoothing*
- Bad against "Salt and Pepper" (noise with values equal to 0 or 255 only) noise
#### Notes:
- Non-linear
- To keep the radius of the Gaussians (the variance) small

<br><br>
\* = (depends on expected result)