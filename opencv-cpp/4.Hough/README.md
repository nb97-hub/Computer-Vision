# HOUGH TRANSFORM
Hough's algorithms are used to detect geometric elements into pictures and solves the boundaries detection problem. The main idea under these algorithms is to exploits the geometric shape parameters-space to fit what has been found from previous edge detection steps. Main Hough's algorithms are:

## Hough Line Transform
To locate straight lines. It exploits parameters from the well-known polar coordinate system (r, $\theta$). When we are in parameter space we can describe the infinite set (or family) of lines passing from a generic point (x<sub>0</sub>, y<sub>0</sub>) as a sinusoid described by the polar couple (r, $\theta$).

After having identified edges with some algorithm (Sobel, Laplacian, Canny, etc), we can then plot the points belonging to that edges in polar parameter space. Thus, we will obtain a set of sinusoid. When it happens that two or more sinusoids intersects, it means that the point belonging to that curves lie on the same line. 

Then with Non-Maximal Suppression and Thresholding we can reduce the number of lines found and keep the most likely ones.

### Standard Hough Transform
- Exploits the previous explaination and returns a vector of couples (r<sub>0</sub>, $\theta$<sub>0</sub>)

### Probabilistic Hough Transform
- Optimized algorithm which returns the extremes of the detected lines (x<sub>0</sub>, y<sub>0</sub>) (x<sub>1</sub>, y<sub>1</sub>).

## Hough Circle Transform
Exploits the same ideas of the algorithm used for lines but adapt it to find circles. There's some tricky math here too. In OpenCV we are asked to choose between two different implementations of the original algorithm that were created for efficiency reasons.

### Hough Gradient
Composed of two stages:
- Edge detection and finding of possible circle centers.
- Finding of bet radius for each candidate circle center.

### Hough Gradient ALT
Variation of HOUGH_GRADIENT to get better accuracy.

## Generalized Hough Transform
Exploits and expands Hough Transform considerations to general shapes (and objects).
- Quite useful for object detection tasks and template matching.
- Basically extracts and memorizes polar features from a template, creates and memorize a table, then tries to match it on your target picture.
- Is computational and memory demanding. The complecity increases if you try to to add other parameter as Scale and rotation.
- The Ballard's variant is faster than Guil's one.
