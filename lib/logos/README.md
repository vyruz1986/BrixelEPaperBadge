# Logos

This readme describes how to convert logos to the correct format for the LilyGo T5 2.13 board's e-ink display.

## Converting logo's to BMP

Using photoshop:

1. Open the original image
2. Image > Mode > Grayscale
3. Image > Mode > Bitmap
4. Image > Image size, resize to appropriate size
5. Save as > BMP

Converting the BMPs to byte arrays:

1. Go to [Image2Cpp](https://javl.github.io/image2cpp/)
2. Upload all BMPs you wish to convert
3. Leave image settings set to default
4. Under '4. Output', set 'Identifier/prefix:' value to `bmp_`
5. Click **Generate code**
6. Paste all generated code in [logos.h](./logos.h)
