let timeLeft = 30;
        let currentQuestion = 0;
        let score = 0;
        let timer;

        function startQuiz() {
            document.getElementById('quiz').style.display = 'block';
            document.getElementById('score').style.display = 'block'; // Display score at the top
            showQuestion(currentQuestion);
            startTimer();
        }

        function startTimer() {
            clearInterval(timer);
            timeLeft = 30;
            document.getElementById('time').textContent = timeLeft;
            timer = setInterval(() => {
                document.getElementById('time').textContent = timeLeft;
                if (timeLeft <= 0) {
                    clearInterval(timer);
                    nextQuestion();
                }
                timeLeft--;
            }, 1000);
        }

        function nextQuestion() {
            clearInterval(timer);
            const currentQ = document.querySelectorAll('.question')[currentQuestion];
            const selected = currentQ.querySelector('input:checked');
            const correctAnswer = currentQ.dataset.answer;

            if (selected && selected.value === correctAnswer) {
                score++;
                document.getElementById('score').textContent = "Score: " + score;
            }

            currentQuestion++;
            if (currentQuestion < document.querySelectorAll('.question').length) {
                showQuestion(currentQuestion);
                startTimer();
            } else {
                endQuiz();
            }
        }

        function showQuestion(index) {
            const questions = document.querySelectorAll('.question');
            questions.forEach((q, i) => {
                q.style.display = i === index ? 'block' : 'none';
            });
        }

        function endQuiz() {
            clearInterval(timer);
            document.getElementById('score').textContent = "Score final: " + score;
            window.scrollTo({ top: 0, behavior: 'smooth' });
            document.querySelector('#score').style.display = 'block';
            document.getElementById('quiz').style.display = 'none';
            document.getElementById('timer').style.display = 'none';
        }   

        // Start the quiz when the page loads
        window.onload = startQuiz;