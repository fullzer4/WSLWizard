// import { createSignal } from "solid-js";
import { invoke } from "@tauri-apps/api/tauri";

const App = () => {

  function getListWSLDistributions() {
    try {
      invoke('cmd_list_wsl_distributions')
        .then((result: any) => {
          console.log(result)
        })
    } catch (error) {
        console.error('Erro ao listar as distribuições WSL:', error);
    }
  }

  return (
    <div class="container">
        <button onClick={() => getListWSLDistributions()}>test</button>
    </div>
  );
}

export default App;
