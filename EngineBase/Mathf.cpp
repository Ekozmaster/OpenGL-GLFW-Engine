#include"Mathf.hpp"

float Mathf::Clamp(float val, float min, float max){
    if(val < min) val = min;
    if(val > max) val = max;
    return val;
};

float Mathf::RepeatAround(float val, float min, float max){
    float internMin = 0;
    float internMax = max - min;
    float internVal = val - min;

    if(internVal > internMax){
        int ranges = internVal / internMax;
        return val - ranges * internMax;
    }else if(internVal < internMin){
        int ranges = -(internVal / internMax - 1);
        return val + ranges * internMax;
    }
    return val;

};

float Mathf::Abs(float val){
    if(val < 0) return -val;
    return val;
};
// Uses a third grade interpolation function, f(x) = 3x^2 - 2x^3.
float Mathf::SmoothInterpolation(float val1, float val2, float t){
    return (val2 - val1) * (3*t*t - 2*t*t*t) + val1;
};

float PerlinNoise::Noise2D(float x, float y){
    int x0 = (int)x;
    int y0 = (int)y;
    int x1 = x0+1;
    int y1 = y0+1;

    float xDispl = x - x0;
    float yDispl = y - y0;

    Vector3 x0y0grad = GradientVectors[PermTable[(y0 + PermTable[x0 % 512]) % 256]];
    Vector3 x1y0grad = GradientVectors[PermTable[(y0 + PermTable[x1 % 512]) % 256]];
    Vector3 x0y1grad = GradientVectors[PermTable[(y1 + PermTable[x0 % 512]) % 256]];
    Vector3 x1y1grad = GradientVectors[PermTable[(y1 + PermTable[x1 % 512]) % 256]];

    Vector3 x0y0Disp = Vector3(xDispl,yDispl,0);
    Vector3 x1y0Disp = Vector3(1-xDispl,yDispl,0);
    Vector3 x0y1Disp = Vector3(xDispl,1-yDispl,0);
    Vector3 x1y1Disp = Vector3(1-xDispl,1-yDispl,0);

    float x0y0Scalar = Vector3::Dot(x0y0Disp, x0y0grad);
    float x1y0Scalar = Vector3::Dot(x1y0Disp, x1y0grad);
    float x0y1Scalar = Vector3::Dot(x0y1Disp, x0y1grad);
    float x1y1Scalar = Vector3::Dot(x1y1Disp, x1y1grad);

    float xBotWeight = Mathf::SmoothInterpolation(x0y0Scalar, x1y0Scalar, xDispl);
    float xTopWeight = Mathf::SmoothInterpolation(x0y1Scalar, x1y1Scalar, xDispl);
    return Mathf::SmoothInterpolation(xBotWeight, xTopWeight, yDispl);
};

// Implement a 3D Noise.
float PerlinNoise::Noise3D(float x, float y, float z){
    int x0 = (int)x;
    int y0 = (int)y;
    int z0 = (int)z;
    int x1 = x0+1;
    int y1 = y0+1;
    int z1 = z0+1;

    float xDispl = x - x0;
    float yDispl = y - y0;
    float zDispl = z - z0;

    Vector3 x0y0z0grad = GradientVectors[PermTable[(z0+ PermTable[(y0 + PermTable[x0 % 512])%512])%512]%256];
    Vector3 x0y0z1grad = GradientVectors[PermTable[(z1+ PermTable[(y0 + PermTable[x0 % 512])%512])%512]%256];
    Vector3 x0y1z0grad = GradientVectors[PermTable[(z0+ PermTable[(y1 + PermTable[x0 % 512])%512])%512]%256];
    Vector3 x0y1z1grad = GradientVectors[PermTable[(z1+ PermTable[(y1 + PermTable[x0 % 512])%512])%512]%256];
    Vector3 x1y0z0grad = GradientVectors[PermTable[(z0+ PermTable[(y0 + PermTable[x1 % 512])%512])%512]%256];
    Vector3 x1y0z1grad = GradientVectors[PermTable[(z1+ PermTable[(y0 + PermTable[x1 % 512])%512])%512]%256];
    Vector3 x1y1z0grad = GradientVectors[PermTable[(z0+ PermTable[(y1 + PermTable[x1 % 512])%512])%512]%256];
    Vector3 x1y1z1grad = GradientVectors[PermTable[(z1+ PermTable[(y1 + PermTable[x1 % 512])%512])%512]%256];

    Vector3 x0y0z0Disp = Vector3(xDispl, yDispl, zDispl);
    Vector3 x0y0z1Disp = Vector3(xDispl, yDispl, 1-zDispl);
    Vector3 x0y1z0Disp = Vector3(xDispl, 1-yDispl, zDispl);
    Vector3 x0y1z1Disp = Vector3(xDispl, 1-yDispl, 1-zDispl);
    Vector3 x1y0z0Disp = Vector3(1-xDispl, yDispl, zDispl);
    Vector3 x1y0z1Disp = Vector3(1-xDispl, yDispl, 1-zDispl);
    Vector3 x1y1z0Disp = Vector3(1-xDispl, 1-yDispl, zDispl);
    Vector3 x1y1z1Disp = Vector3(1-xDispl, 1-yDispl, 1-zDispl);

    float x0y0z0Scalar = Vector3::Dot(x0y0z0grad, x0y0z0Disp);
    float x0y0z1Scalar = Vector3::Dot(x0y0z1grad, x0y0z1Disp);
    float x0y1z0Scalar = Vector3::Dot(x0y1z0grad, x0y1z0Disp);
    float x0y1z1Scalar = Vector3::Dot(x0y1z1grad, x0y1z1Disp);
    float x1y0z0Scalar = Vector3::Dot(x1y0z0grad, x1y0z0Disp);
    float x1y0z1Scalar = Vector3::Dot(x1y0z1grad, x1y0z1Disp);
    float x1y1z0Scalar = Vector3::Dot(x1y1z0grad, x1y1z0Disp);
    float x1y1z1Scalar = Vector3::Dot(x1y1z1grad, x1y1z1Disp);

    // Computing weights for lower plane interpolation.
    float x0x1BotBackWeight = Mathf::SmoothInterpolation(x0y0z0Scalar, x1y0z0Scalar, xDispl);
    float x0x1BotFrontWeight = Mathf::SmoothInterpolation(x0y0z1Scalar, x1y0z1Scalar, xDispl);
    float lowerPlaneWeight = Mathf::SmoothInterpolation(x0x1BotBackWeight, x0x1BotFrontWeight, zDispl);
    // Computing weights for upper plane interpolation.
    float x0x1TopBackWeight = Mathf::SmoothInterpolation(x0y1z0Scalar, x1y1z0Scalar, xDispl);
    float x0x1TopFrontWeight = Mathf::SmoothInterpolation(x0y1z1Scalar, x1y1z1Scalar, xDispl);
    float upperPlaneWeight = Mathf::SmoothInterpolation(x0x1TopBackWeight, x0x1TopFrontWeight, zDispl);
    return Mathf::SmoothInterpolation(lowerPlaneWeight, upperPlaneWeight, yDispl);
};
