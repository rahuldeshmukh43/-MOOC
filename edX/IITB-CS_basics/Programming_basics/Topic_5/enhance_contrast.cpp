/* Program: enhance_contrast.cpp
A program which reads the pixel intensities for a grayscale image,
calculates the histogram and the cumulative distribution function,
and finally recalculates the pixel values, such that the histogram is
equalized. This procedure gives us an image with better contrast.
Procedure and formula is based on the material given on wikipedia
*/
#include<iostream>
#include<cmath>
using namespace std;
int main() {
    int i, j, min=0, M, N;
    int image[500][500], newimage[500][500];
    int histogram[256], cdf[256], equalizer[256];
// Read Image data
    cout << " Give the image size: Height M and width N"<<endl;
    cin >> M >> N;
    cout<<M<<"\t"<<N<<endl;
    for(i=0; i<M; i++) {
        for(j=0; j<N; j++) {
            cin>>image[i][j];
        }
    }
    cout<<endl<<"Original Image:"<<endl;
    for(i=0; i<M; i++) {
        for(j=0; j<N; j++) {
            cout << image[i][j]<<"\t"; // output the image
        }
        cout<<endl;
    }
    for(i=0; i<256; i++) {
// Initialize all array elements of histogram, cdf, equalizer to 0
        histogram[i]=0;
        cdf[i]=0;
        equalizer[i]=0;
    }
    /* calculate histogram table entries */
    for (i=0; i<M; i++) {
        for (j=0; j<N; j++) {
// principle of associative array is used
// Value of the pixel itself is the "key" or index in the histogram table
// indicates the element which must be incremented
            histogram[ image[i][j] ]++;
        }
    }
    /* calculate cdf table entries */
    cdf[0] = histogram[0];
    for(i=1; i<256; i++) {
        cdf[i]= cdf[i-1] + histogram[i];
    }
    /* Find the minimum nonzero value in cdf table */
    min =255;
    for (i=0; i < 256; i ++) {
        if (cdf[i] < min && cdf[i] != 0) min =cdf[i];
    }
    /* Calculate entries in the equalizer table */
    for (i=0; i<256; i++) {
        equalizer[i]=round((float)(cdf[i]-min)/(M*N-min)*(256-1));
    }
    /* Calculate entries in the newimage array */
    for(i=0; i<M; i++) {
        for(j=0; j<N; j++) {
            newimage[i][j] = equalizer[ image[i][j] ];
        }
    }
    cout<<endl<<"New Image: "<<endl;
    for(i=0; i<M; i++) {
        for(j=0; j<N; j++) {
            cout << newimage[i][j]<<"\t"; // output the image
        }
        cout<<endl;
    }
    return 0;
}
