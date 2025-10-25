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

## Dilatation
- Adds pixels to object boundaries, helping to fill gaps and connect broken parts of an object.
- Expansion or Thickning.

## Erosion
- Removes pixels from object boundaries, useful for eliminating small noise and disconnecting weakly connected components.
- Reduction or Thining.

## Opening
- It's the erosion followed by dilatation.
- Is a well known noise removal operation. Remove small foreground objects while preserving shape of larger ones.

## Closing
- It's the dilatation followed by erosion.
- Is a well known hole filling technique.

## Morphological Gradient
- It's the difference between dilatation and erosion.
- It is useful for finding the outline of an object.
    
<br><br>
# Scaling
It is possible and sometimes convinient to **downscale** (or equivalently downsize/downsample/zoom out) or **upscale** (or equivalently upsize/upsample/zoom in) an image. To perform these operations we can use Gaussian pyramids (1<sup>st</sup> order derivative) or Laplacian pyramids (2<sup>nd</sup> order derivative).

Note: when we downsample and then upsample, we are actually blurring, even if the resulting image has the same size of the initial one. Basically, reducing an image
causes lose of information.

## Downscaling (Gaussian)
- Combination of two subsequent operations:
    - Convolution with a Normalized Gaussian Kernel.
    - Removal of all even-numbered rows and columns.
- In OpenCV use **pyrDown**.

## Upscaling (Gaussian)
- Combination of two subsequent operations:
    - Upsize of the image to twice the original in each dimension. Note that the new even-numbered rows and columns are zero-filled.
    - Convolution with a Normalized Gaussian Kernel. Same kernel as above but with 4x value elements. 
- In OpenCV use **pyrUp**.    

<br><br>
# Thresholding
It is the simplest segmentation method. The separation between objects is due to pixels intensities. The thresholding methods depend on the threshold value (T) and the value to assign to a pixel whether it is greater or smaller compared to T.

Notes: 
- T             -> threshold value.
- output(x,y)   -> output image pixel at coordinate (x,y).
- input(x,y)    -> input image pixel at coordinate (x,y).
- maxVal        -> max intensity value (255 in case of CV_8UC)

## Threshold Binary
- **output(x,y) = input(x,y) > T ? maxVal : 0**

## Threshold Binary Inverted
- **output(x,y) = input(x,y) > T ? 0 : maxVal**

## Threshold Truncate
- **output(x,y) = input(x,y) > T ? T : input(x,y)**

## Threshold to Zero
- **output(x,y) = input(x,y) > T ? input(x,y) : 0**

## Threshold to Zero Inverted
- **output(x,y) = input(x,y) > T ? 0 : input(x,y)**

## Threshold, HSV and inRange
- HSV is the colorspace model to represent Hue, Saturation and Value.
- Hue is basically the color type.
- Therefore is useful to employ HSV when we want to track objects based on their color.
- **threshold_video.cpp** is an application that allows the user:
    - To play with the HSV.
    - To locate a colorspace range in which their object fits.
    - To track the object very fast (no NN employed) based on its color.