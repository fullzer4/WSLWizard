import { createEffect, createSignal, onCleanup } from "solid-js";
import { invoke } from "@tauri-apps/api/tauri";
import "./scss/index.scss"
import "./scss/screen.scss"
import Graph from "./components/graph";
import State from "./components/state";
import Gear from "./components/gear";

type TPercenteage = [number?, number?, number?, number?, number?, number?, number?, number?, number?, number?];

const App = () => {

  const [distros, setDistros] = createSignal<Array<string>>([]);
  const [disk, setDisk] = createSignal<Array<TPercenteage>>([]);
  const [ram, setRam] = createSignal<Array<TPercenteage>>([]);
  const [cpu, setCpu] = createSignal<Array<TPercenteage>>([]);
  const [gpu, setGpu] = createSignal<Array<TPercenteage>>([]);

  const getListWSLDistributions = () => {
    try {
      invoke('cmd_list_wsl_distributions')
        .then((result: any) => {
          setDistros(result.distros);
        })
    } catch (error) {
        console.error('Erro ao listar as distribuições WSL:', error);
    }
  }

  createEffect(() => {
    const intervalId = setInterval(() => {
      
    }, 1000);

    onCleanup(() => {
      clearInterval(intervalId);
    });
  })

  getListWSLDistributions()

  return (
    <div class="container">
      {distros().map((distro: any) => (
        <div class="distrobox">
          <div class="box1">
            <div>
              <p>{distro.name}</p>
              <State state={false}/>
            </div>
            <Graph
              label="Disk%:"
              signal={disk}
            />
          </div>
          <div class="box2">
            <div class="graphs">
              <Graph
                label="Cpu%:"
                signal={cpu}
              />
              <Graph
                label="Ram%:"
                signal={ram}
              />
              <Graph
                label="Gpu%:"
                signal={gpu}
              />
            </div>
            <div class="buttons">
              <button>OPEN</button>
              <button>LOGS</button>
              <button>NETWORK</button>
              <button>FIREWALL</button>
              <button><Gear/></button>
            </div>
          </div>
        </div>
      ))}
    </div>
  );
}

export default App;
