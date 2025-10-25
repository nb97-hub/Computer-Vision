# Image Filtering
- Useful for preprocessing images and generally speaking for removing noise.
- Linear and Non-Linear filters exist.
- A linear filter implemented as convolution is also called LSIS (Linear Shift Invariant System).
- LSIS <=> Convolution.
- Using filters in OpenCV usually means to specify also what to do with the non-existing pixels belonging to the borders. Two common approaches are:
    - replicating the borders by assigning the non existing pixels the same values of neighbour pixels.
    - assume a constant border by assigning a specific value (for example 0).
    
<br><br>
# Smoothing
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
<br>
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
<br>
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

<br><br>
# Morphological Operations<br>(Iterative Modifications)
- Mainly used to process Binary Images.
- Set of operations that process images based on shapes. Morphological operations apply a structuring element to an input image and generate an output image.
Basic morphological operations are: Dilation and Erosion.
- Opening (erosion followed by dilatation) is a well known noise removal operation. Remove small foreground objects while preserving shape of larger ones.
- Closing (dilatation followed by erosion) is a well known hole filling technique.

## Dilatation
- Adds pixels to object boundaries, helping to fill gaps and connect broken parts of an object.

## Erosion
- Removes pixels from object boundaries, useful for eliminating small noise and disconnecting weakly connected components.
