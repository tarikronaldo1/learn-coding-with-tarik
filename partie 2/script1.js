const quizContainer = document.getElementById('quiz-container');
const scoreElement = document.getElementById('score');
const timerElement = document.getElementById('timer');
const submitButton = document.getElementById('submit-quiz');
let quizData = [];
let score = 0;
let currentQuestionIndex = 0;
let timer;
let quizSubmitted = false;
scoreElement.style.display = 'block';
scoreElement.textContent = `Score : ${score}`;
// Générer le quiz depuis l'API
document.getElementById('generate').addEventListener('click', async () => {
    const numQuestions = document.getElementById('number').value;
    const category = document.getElementById('category').value;
    const difficulty = document.getElementById('difficulty').value;
    const type = document.querySelector('[name="trivia_type"]').value;
    const encoding = document.querySelector('[name="trivia_encode"]').value;
    // Validation: Ensure all fields are selected
    if (!numQuestions || !difficulty || !type || type === "" || !encoding || !category) {
        alert('Veuillez remplir tous les champs avant de générer le quiz.');
        return;
    }
    // Construct API URL dynamically
    let apiUrl = `https://opentdb.com/api.php?amount=${numQuestions}`;
    if (category !== "any") apiUrl += `&category=${category}`;
    if (difficulty !== "any") apiUrl += `&difficulty=${difficulty}`;
    if (type !== "any") apiUrl += `&type=${type}`;
    if (encoding !== "default") apiUrl += `&encode=${encoding}`;
    const res = await fetch(apiUrl);
    const data = await res.json();
    quizData = data.results.map((q) => ({
    question: decodeURIComponent(q.question),
    options: [...q.incorrect_answers.map(decodeURIComponent), decodeURIComponent(q.correct_answer)]
    .sort(() => Math.random() - 0.5),
    correct: decodeURIComponent(q.correct_answer)
}));
    scoreElement.textContent = `Score : ${score}/${quizData.length}`;
    currentQuestionIndex = 0;
    quizSubmitted = false;
    
    displayQuestion();
});
// Afficher la question actuelle
function displayQuestion() {
    if (currentQuestionIndex >= quizData.length) {
        endQuiz();
        return;
    }

    quizContainer.innerHTML = '';
    const q = quizData[currentQuestionIndex];
    const questionBlock = document.createElement('div');
    questionBlock.classList.add('question-block');
    questionBlock.innerHTML = `<h3>${currentQuestionIndex + 1}. ${q.question}</h3>`;

    q.options.forEach((option, i) => {
        const optionContainer = document.createElement('div');
        optionContainer.classList.add('option-container');
        optionContainer.innerHTML = `
            <label for="option${currentQuestionIndex}-${i}">${option}</label>
            <input type="radio" name="question${currentQuestionIndex}" value="${option}" id="option${currentQuestionIndex}-${i}">
        `;
        questionBlock.appendChild(optionContainer);
    });

    quizContainer.appendChild(questionBlock);

    if (currentQuestionIndex < quizData.length - 1) {
        const nextButton = document.createElement('button');
        nextButton.textContent = 'Suivant';
        nextButton.addEventListener('click', nextQuestion);
        quizContainer.appendChild(nextButton);
    } else {
        submitButton.style.display = 'block';
    }

    startTimer(10);
}

// Passer à la question suivante
function nextQuestion() {
    const selectedOption = document.querySelector(`input[name="question${currentQuestionIndex}"]:checked`);

    if (!timerExpired && !selectedOption) {
        alert('Veuillez sélectionner une réponse avant de passer à la question suivante.');
        return;
    }

    clearInterval(timer);

    // Vérifier la réponse et mettre à jour le score
    if (selectedOption && selectedOption.value === quizData[currentQuestionIndex].correct) {
        score++;  // Incrémenter le score
        updateScore();  // Mettre à jour l'affichage du score
    }

    currentQuestionIndex++;
    timerExpired = false; // Reset for the next question

    if (currentQuestionIndex < quizData.length) {
        displayQuestion();
    } else {
        endQuiz();
    }
}

// Mettre à jour le score affiché
function updateScore() {
    scoreElement.textContent = `Score : ${score}/${quizData.length}`;
}

// Soumettre le quiz
submitButton.addEventListener('click', endQuiz);

function endQuiz() {
    if (quizSubmitted) return;

    clearInterval(timer);
    timerElement.style.display = 'none';

    quizSubmitted = true;

    // Vérifie si un bouton "Rejouer" existe déjà avant d'en ajouter un
    if (!document.getElementById('restart-button')) {
        const restartButton = document.createElement('button');
        restartButton.textContent = "Rejouer";
        restartButton.id = "restart-button";
        restartButton.style.marginTop = "10px";
        restartButton.addEventListener('click', () => location.reload());
        quizContainer.appendChild(restartButton);
    }

    window.scrollTo({ top: 0, behavior: 'smooth' });
}

// Démarrer le timer
function startTimer(seconds) {
    let timeLeft = seconds;
    timerExpired = false;
    timerElement.style.display = 'block';
    timerElement.textContent = `Temps restant : ${timeLeft}s`;

    timer = setInterval(() => {
        timeLeft--;
        timerElement.textContent = `Temps restant : ${timeLeft}s`;

        if (timeLeft <= 0) {
            clearInterval(timer);
            timerExpired = true;
            nextQuestion(); // Passer à la question suivante automatiquement
        }
    }, 1000);
}
