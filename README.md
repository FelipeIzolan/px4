<img width="168" height="84" alt="image" src="https://github.com/user-attachments/assets/f37f9d8b-5ecd-4c96-b541-bd6ba634ae91" />

Palette-indexed 4-bit image format.

## 💾 Format

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
      <td>Image width.</td>
    </tr>
    <tr>
      <td>4</td>
      <td>1</td>
      <td>Image height.</td>
    </tr>
    <tr>
      <td>5</td>
      <td>(Image width * Image height + 1) / 2</td>
      <td>Image data</td>
    </tr>
  </tbody>
</table>
