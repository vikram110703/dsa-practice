/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    const v=[];
    // for(let i=0;i<arr.length;i++)
    //     {
    //         v[i]=fn(arr[i],i);
    //     }
    // return v;
    
    // m-2....
    
    arr.forEach((element,index)=>{
        v[index]=fn(element,index);
    });
    return v;
};