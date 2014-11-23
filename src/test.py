import cv2 as cv
import numpy as np

mat = cv.imread("path.png",1)

print mat.shape[0],"--",mat.shape[1]
cv.namedWindow("Display window", cv.CV_WINDOW_AUTOSIZE)
cv.imshow("Display window",mat)
cv.waitKey(0)

