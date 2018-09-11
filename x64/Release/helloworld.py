from maze_env import Maze
from RL_brain import DeepQNetwork
def run_maze():
    step = 0
    for episode in range(300):
        # initial observation
        observation = env.reset()

        while True:
            # fresh env
            env.render()

            # RL choose action based on observation
            action = RL.choose_action(observation)

            # RL take action and get next observation and reward
            observation_, reward, done = env.step(action)

            RL.store_transition(observation, action, reward, observation_)

            if (step > 200) and (step % 5 == 0):
                RL.learn()

            # swap observation
            observation = observation_

            # break while loop when end of this episode
            if done:
                break
            step += 1

    # end of game
    print('game over')
    env.destroy()


# if __name__ == "__main__":
#     # maze game
#     env = Maze()
#     RL = DeepQNetwork(env.n_actions, env.n_features,
#                       learning_rate=0.01,
#                       reward_decay=0.9,
#                       e_greedy=0.9,
#                       replace_target_iter=200,
#                       memory_size=2000,
#                       # output_graph=True
#                       )
#     env.after(100, run_maze)
#     env.mainloop()
#     RL.plot_cost()
def hello():
    #print("hello")
    from maze_env import Maze
    from RL_brain import DeepQNetwork
    global env
    env = Maze()
    global RL
    RL = DeepQNetwork(env.n_actions, env.n_features,
                      learning_rate=0.01,
                      reward_decay=0.9,
                      e_greedy=0.9,
                      replace_target_iter=200,
                      memory_size=2000,
                      # output_graph=True
                      )
    env.after(100, run_maze)
    env.mainloop()
    #RL.plot_cost()
def plot():
    a = [1, 2, 3]
    file = open('cost_his.txt', 'w');
    file.write(str(a));
    file.close();
    import matplotlib.pyplot as plt

    x = [1, 2, 3]

    y = [1, 20, 3]

    x2 = [2, 3, 4]

    y2 = [2, 14, 8]

    plt.plot(x, y, label='First one')

    plt.plot(x2, y2, label='Second one')

    plt.xlabel('x')

    plt.ylabel('y')

    plt.title('Interesting\nChick it out')

    plt.legend()

    plt.show()
def TestList(nlist):
    a=[1,2,3]
    print(nlist)
    return a
