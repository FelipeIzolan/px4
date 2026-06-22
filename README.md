<img width="168" height="84" alt="image" src="https://github.com/user-attachments/assets/f37f9d8b-5ecd-4c96-b541-bd6ba634ae91" />

Palette-indexed 4-bit image format.

## 📄 File structure

<table>
  <thead>
    <tr>
      <th>Offset (Bytes)</th>
      <th>Size (Bytes)</th>
      <th>Description</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>0</td>
      <td>3</td>
      <td>The identity of "PX4".</td>
    </tr>
    <tr>
      <td>3</td>
      <td>1</td>
      <td>Image width; The maximum width is 255.</td>
    </tr>
    <tr>
      <td>4</td>
      <td>1</td>
      <td>Image height; The maximum height is 255.</td>
    </tr>
    <tr>
      <td>5</td>
      <td>2</td>
      <td>Image data size; The maximum size is 32513 bytes.</td>
    </tr>
    <tr>
      <td>7</td>
      <td>~</td>
      <td>Image data.</td>
    </tr>
  </tbody>
</table>


### 4-bit per index
<img width="196" height="116" alt="image" src="https://github.com/user-attachments/assets/8b4374de-ff49-47e1-991f-701cec55f90e" />

Each index is represented by a 4-bit value, allowing a palette of 16 colors.\
To optimize storage, two 4-bit values are packed into a single byte, making the file 2x smaller.

> **Curiosity**: A 4-bit value is called 'nibble'.

### Run-length Encoding Algorithm

...
