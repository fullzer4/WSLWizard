import { Accessor } from "solid-js"

type TGraphProps = {
    label: string,
    signal: Accessor<Array<any>>
}

const Graph = (props: TGraphProps) => {
    return(
        <div>
            <p>{props.label}</p>
        </div>
    )
}

export default Graph