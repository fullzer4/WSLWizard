import { createSignal } from "solid-js";
import { invoke } from "@tauri-apps/api/tauri";
import "./scss/index.scss"
import "./scss/screen.scss"
import Graph from "./components/graph";
import State from "./components/state";
import Gear from "./components/gear";

const App = () => {

  const [distros, setDistros] = createSignal([]);

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

  getListWSLDistributions()

  return (
    <div class="container">
      {distros().map((distro: any) => (
        <div class="distrobox">
          <div>
            <div>
              <p>{distro.name}</p>
              <State state={false}/>
            </div>
            <Graph
              label="Disk%:"
            />
          </div>
          <div>
            <div>
              <Graph
                label="Cpu%:"
              />
              <Graph
                label="Ram%:"
              />
              <Graph
                label="Gpu%:"
              />
            </div>
            <div>
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
