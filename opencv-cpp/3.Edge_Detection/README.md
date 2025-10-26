# Edge Detection
Edge detection is a fundamental technique in image processing and computer vision that identifies the boundaries or edges of objects within images. Edges correspond to significant changes in brightness or color.

Extracting relevant structural information from images, enable machines to "see" and analyze images more effectively. Indeed, by focusing on edges, the complexity of an image is reduced, making further tasks such as object recognition, classification, and scene understanding more efficient.​

## Applications
- **Medical Imaging**: Enhancing features in MRI, CT scans, and X-rays to detect abnormalities like tumors or organ boundaries.

- **Autonomous Vehicles**: Identifying lane markings, obstacles, and road signs for safe navigation.

- **Robotics**: Allowing robots to perceive and interact with their environment by recognizing object edges.

- **Security and Surveillance**: Detecting intruders, motion, and tracking objects in video feeds.

- **Satellite Imagery**: Improving map details and identifying geographical features.

- **Fingerprint Recognition**: Extracting ridge patterns based on edges for identification.

- **Photography and Visual Effects**: Enhancing image details and artistic modifications.​

## Famous algorithms
### Sobel
Based on 1<sup>st</sup> order gradient. Sobel pre-coputed some kernels that approximate the gradient in x or y direction. Thus the algorithm consists in convolving such kernels with the image.

#### Pros:
- Very Fast (Low computational cost) - single kernel convolution
- Precise in localizing horizontal and vertical edges
- Provides Edges: Localization, Orientation and Magnitudo
#### Cons:
- Noise Sensitivity
- No-guarantees on borders continuity or connectivity
- Less precise in localizing diagonal borders
- Could require Thresholding (depends on the implementation)
- Requires x2 convolutions (for horizontal and vertical axes) plus a non-linear operation (to combine the reteived information)
#### Notes:
- Often adopted in real time embedded devices
- Returns thick borders
- Given a Sobel Kernel k x k, higher k implies:
    - Poor Orientation Accuracy
    - Less Noise Sensitivity
    - Better Detection

<br>

### Laplacian (LoG)
Based on 2<sup>nd</sup> order gradient and zero-crossing localization. The plain algorithm has high noise sensibility, but usually it's employed the improved version that exploits the adoption of a Gaussian Blur (to reduce the noise) and some pre-computing. In this way at runtime we obtain better performances within the same time window of the original algorithm. This method is also called **LoG** (Laplacian of Gaussian).

#### Pros:
- Fast (Moderate Computational Cost)
- Requires only one convolution (neither thresholding nor non-linear ops)
- Provides Edges Localization only
- Returns thin borders, connected and accurate borders
- Best algorithm to analyze blob-shaped images. Thus images that contains bubbles, rounded lights, bright spots on dark backgrounds (like astronomical images)
#### Cons:
- Noise Sensitivity
- Do not provides edges: orientation and magnitudo
#### Notes:
- Mainly adopted in medical imaging, industrial inspection and astronomy

<br>

### Canny Edge Detector
Multi-stage that implies: 2D Gaussian Blur, 2D Sobel and 1D Laplacian (and some non-linear operations)
#### Pros:
- Very Accurate
- Thin, connected and accurate borders (better than Laplacian)
- Provides Edges: Localization, Orientation and Magnitudo
- Low Noise Sensitivity (best $signal/noise$ performances)
#### Cons:
- Quite Slow (High Complexity x10/x20 wrt Sobel)
#### Notes:
- Adopted in medical imaging, autonomous driving and critical or high-accuracy demanding systems
