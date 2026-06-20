//CallBack Hell

// function getData(dataId,getNextData){
    
//     setTimeout(() => {
//         console.log("data : " , dataId);
//         getNextData();
//     },2000);
// }

// getData(1,() => {
//     console.log("getting data 2");
//     getData(2,()=>{
//         console.log("getting data 3");
//         getData(3,() => {
//             console.log("geting Data 4");
//             getData(4);
//         });
//     });
// });

//Promise Chain

function getData(dataId,getNextData){
    
    setTimeout(() => {
        console.log("data : " , dataId);
        getNextData();
    },2000);
}

// let p1 = getData(1);
getData(1).then((res) => {
    console.log(res);//data \n success
    getData(2).then((res) => {
        console.log(res);
        getData(3).then((res) => {
            console.log(res);
        });
    });
});

//OR
console.log("getting Data 1");
getData(1)
  .then((res) => {
    console.log("getting Data 2");
    return getData(2);
  })
  .then((res) => {
    // console.log(res);
    console.log("getting Data 3");
    return getData(3);
  })
  .then((res) => {
    console.log(res);
  })