# Image Transformations $3\times3$
These transformations make use of Homogenous Coordinates that can represent a 2D point $p = (x,y)$ in 3D space as $\tilde{p} = (\tilde{x},\tilde{y},\tilde{z})$. The third coordinate $\tilde{z} \neq 0$ such that: $x = \frac{\tilde{x}}{\tilde{z}}$ and $y = \frac{\tilde{y}}{\tilde{z}}$. 

This representation is useful to describe **Affine Transformations** and **Homography Transformations** as matrices that can easly convert images as if they are percieved from another POV.

## Affine Transformations
- Embeds warps as: **Translation**, Rotation, Scaling, Skew, Mirroring.
- The Affine matrix look like this A = {[a<sub>11</sub> a<sub>12</sub> a<sub>13</sub>], [a<sub>21</sub> a<sub>22</sub> a<sub>23</sub>], **[0, 0, 1]**}. 
- The values at a<sub>13</sub> and a<sub>23</sub> are the ones responsible to translation, thus they are also represented as $t_x$ and $t_y$ respectively because are in charge of moving the image in the x and y directions.
- The Affine transformation is $[x_2, y_2,1]^T = [\tilde{x_2}, \tilde{y_2},\tilde{z_2}]^T = A [\tilde{x_1}, \tilde{y_1},\tilde{z_1}]^T$
- These transformations are defined by a set of properties that bind the original image to the transformed one:
    - Origin does not necessarily map to origin (due to translation)
    - Lines map to lines
    - Parallel lines remain parallel
    - It's an operation Closed under composition


## Homography or Projective Transformation
- Like affine transformations BUT transformation matrix is not restricted to have as a last row [**0, 0, 1**].
- Homography Matrix H = {[a<sub>11</sub> a<sub>12</sub> a<sub>13</sub>], [a<sub>21</sub> a<sub>22</sub> a<sub>23</sub>], **[a<sub>31</sub> a<sub>32</sub> a<sub>33</sub>]**}.
- Due to a property of Homogenous Coordinates, we can scale the homography (multiply H by a constant factor k) but we will obtain the same transformation.
- It's also called Projective because this transformation maps a plane to another plane through a point (like pinhole).
- These transformations are defined by a set of properties that bind the original plane to the transformed one:
    - Origin does not necessarily map to origin (due to translation)
    - Lines map to lines
    - **Parallel lines do not necessarily map parallel**
    - It's an operation Closed under composition
- Homography is the core part of the pipeline of algorithms needed for Image Stitching along with SIFT (for detecting matching points) and RANSAC (to deal with outliers points).