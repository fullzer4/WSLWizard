import { Accessor } from "solid-js"
import { Line } from 'solid-chartjs'

type TGraphProps = {
    label: string,
    signal: Accessor<Array<any>>
}

const Graph = (props: TGraphProps) => {

    const chartData = {
        labels: ['January', 'February', 'March', 'April', 'May'],
        datasets: [
            {
                label: 'Sales',
                data: [50, 60, 70, 80, 30],
            },
        ],
    }

    const chartOptions = {
        responsive: false,
        maintainAspectRatio: false,
        plugins: {
            legend: {
                display: false,
            },
            tooltip: {
                enabled: false,
            },
        },
        scales: {
            x: {
                display: false,
            },
            y: {
                display: false,
            },
        },
    }

    return(
        <div>
            <p>{props.label}</p>
            <Line data={chartData} options={chartOptions} width={100} height={100} />
        </div>
    )
}

export default Graph