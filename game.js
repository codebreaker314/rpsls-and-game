function preload() {
  this.load.image('bug1', 'https://s3.amazonaws.com/codecademy-content/courses/learn-phaser/physics/bug_1.png');
  this.load.image('bug2', 'https://s3.amazonaws.com/codecademy-content/courses/learn-phaser/physics/bug_2.png');
  this.load.image('bug3', 'https://s3.amazonaws.com/codecademy-content/courses/learn-phaser/physics/bug_3.png');
  this.load.image('platform', 'https://s3.amazonaws.com/codecademy-content/courses/learn-phaser/physics/platform.png');
  this.load.image('codey', 'https://s3.amazonaws.com/codecademy-content/courses/learn-phaser/physics/codey.png');
}

const gameState = {
  score: 0
};

function create() {
  gameState.player = this.physics.add.sprite(225, 450, 'me').setScale(.5);

  const platforms = this.physics.add.staticGroup();

  platforms.create(225, 490, 'platform').setScale(1, .3).refreshBody();
	platforms.create(525, 490, 'platform').setScale(1, .3).refreshBody();
  platforms.create(225, 490, 'platform').setScale(1, .3).refreshBody();
	platforms.create(725, 490, 'platform').setScale(1, .3).refreshBody();
  gameState.scoreText = this.add.text(450, 485, 'Score: 0', { fontSize: '15px', fill: '#000000' });

  gameState.player.setCollideWorldBounds(true);

  this.physics.add.collider(gameState.player, platforms);

	gameState.cursors = this.input.keyboard.createCursorKeys();

  const bugs = this.physics.add.group();

  function bugGen () {
    const xCoord = Math.random() * 865;
    bugs.create(xCoord, 0, 'bug1');
    bugs.create(xCoord, 10, 'bug2');
    bugs.create(xCoord, 20, 'bug3');
    bugs.create(xCoord, 30, 'bug4');
  }

  const bugGenLoop = this.time.addEvent({
    delay: 90,
    callback: bugGen,
    callbackScope: this,
    loop: true,
  });

  this.physics.add.collider(bugs, platforms, function (bug) {
    bug.destroy();
    gameState.score += 10;
    gameState.scoreText.setText(`Score: ${gameState.score}`);
  })

  this.physics.add.collider(gameState.player, bugs, () => {
    bugGenLoop.destroy();
    this.physics.pause();
    this.add.text(425, 250, 'Game Over', { fontSize: '15px', fill: '#000000' });
    this.add.text(400, 270, 'Click to Restart', { fontSize: '15px', fill: '#000000' });

		// Add your code below:
    this.input.on('pointerup', () =>{
      gameState.score = 0;
    	this.scene.restart();
    });
  });
}

function update() {
  if (gameState.cursors.left.isDown) {
    gameState.player.setVelocityX(-160);
  } else if (gameState.cursors.right.isDown) {
    gameState.player.setVelocityX(160);
  } else if (gameState.cursors.up.isDown) {
    gameState.player.setVelocityY(-160);
  }else if (gameState.cursors.down.isDown) {
    gameState.player.setVelocityY(0);
  }else if (gameState.cursors.shift.isDown) {
    gameState.player.setVelocityY(-100000);
  }else{
    gameState.player.setVelocityX(0);
  }
}

const config = {
  type: Phaser.AUTO,
  width: 900,
  height: 500,
  backgroundColor: "b9eaff",
  physics: {
    default: 'arcade',
    arcade: {
      gravity: { y: 200 },
      enableBody: true,
    }
  },
  scene: {
    preload,
    create,
    update
  }
};

const game = new Phaser.Game(config);
