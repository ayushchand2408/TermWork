let userScore = 0;
let compScore = 0;

const choices = document.querySelectorAll(".choice");
const msg = document.querySelector("#msg");

const uScore = document.querySelector("#user-score");
const cScore = document.querySelector("#comp-score");


const genCompChoice = () => {
    const options = ["rock" , "paper" , "scissor"];
    const randIdx = Math.floor(Math.random(options) * 3);
    return options[randIdx];
} 

const drawGame = () =>{
    console.log("game was draw");
    msg.innerText = "Game Draw!";

};

const ShowWinner = (userWin) => {
    if(userWin){
        userScore++;
        msg.innerText = "You Win!";
        uScore.innerText = userScore;
    }
    else{
        compScore++;
        msg.innerText = "You loose!";
        cScore.innerText = compScore;
    }
};

const playGame = (userChoice)=>{
    console.log(userChoice);
    const compChoice = genCompChoice();
    console.log(compChoice)
    if(userChoice === compChoice){
        drawGame();
    }
    else
    {
        let userWin = true;
        if(userChoice === "rock"){
            userWin = compChoice === "paper" ? false : true;
        }
        else if(userChoice === "paper"){
            userWin = compChoice ==="scissor" ? false : true;
        }
        else{
            userWin = compChoice === "rock" ? false : true;
        }
        
        ShowWinner(userWin);
    }
    

};

choices.forEach((choice) => {
    choice.addEventListener("click" , () => {
        const userChoice = choice.getAttribute("id");
        playGame(userChoice)
    })
})
