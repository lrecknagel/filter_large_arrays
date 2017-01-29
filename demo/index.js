const flarr = require("flarr")

const a = [
  {key: "val_01", val: "1000", children: [1,2,3]},
  {key: "val_02", val: "1001", children: [4,5,6]},
  {key: "val_03", val: "1080", children: [99,0,50]},
  {key: "val", val: "100", children: [9]}
]

// arg0 => the array to filter
// arg1 => the obj key where to search for filter string
// arg2 => the filter string
const result = flarr.filter(a, "key", "val_")
console.log(result);
