import React from "react";
import { useParams } from "react-router-dom";
import main from '../img/main.jpeg';
import portrait from '../img/portrait_man.png';
import Vi from '../img/Vibor.png';
import lArrow from '../img/l_arrow.PNG';
import rArrow from '../img/r_arrow.PNG';

const Party = () => {
    const id = useParams();

    return (
        <React.Fragment>
            <div className="header">
                <img 
                    className="main_image" 
                    src={main}  
                    alt="Politikisto_main"
                />
                <p className="title"> Politikisto </p>
                <div className="description">
                <h1>Единая Россия</h1>
                <p>
                    Самая крупная проправительственная политическая партия Российской Федерации, считающаяся "партией власти".<br />
                    Была учреждена 1 декабря 2001. Идеология партии – российский консерватизм
                </p>
                </div>
                <button 
                    className="next next_party" 
                    /*onclick="window.location.href = 'index.html';"*/
                    >
                    <span>Назад</span>
                    <div className="border"></div>
                </button>
                <button 
                    className="about" 
                    /*onclick="window.location.href = 'about.html';"*/
                    >
                    <span>О нас</span>
                </button>
            </div>

            <div className="party_description_1">
                <img src={portrait}/>
            </div>

            <div className="party_params">
                <div className="param1">
                <p className="title">Образование</p>
                <p className="description">Высшее</p>
                </div>
                <div className="param2">
                <p className="title">Место проживания</p>
                <p className="description">Москва</p>
                </div>
                <div className="param3">
                <p className="title">Семейное положение</p>
                <p className="description">Женат</p>
                </div>
                <div className="param4">
                <p className="title">Пол</p>
                <p className="description">Мужчина</p>
                </div>
                <div className="param5">
                <p className="title">Возрастная группа</p>
                <p className="description">20-35 лет</p>
                </div>
                <div className="param6">
                <p className="title">Политические взгляды</p>
                <p className="description">Либеральные</p>
                </div>
                <div className="param7">
                <p className="title">Главное в жизни</p>
                <p className="description">Семья</p>
                </div>
            </div>

            <div className="parties_title">
                <p> Единая Россия </p>
                <img src={Vi} />
            </div>

            <div className="party_description_2">
                <p className="title">Единая Россия</p>
                <p className="description">Соотношение мужчин и женщин в социальной базе, % </p>
                <div id="air"></div>
                <button className="arrow larrow"><img className="larim" src={lArrow}/></button>
                <button className="arrow rarrow"><img className="rarim" src={rArrow}/></button>
            </div>

            <div>

            <p className="q1">„В детстве я хотел стать космонавтом, но надо было много учиться, поэтому я стал президентом“</p>
            <p className="q2">Джоржд Буш</p>
            </div>

            <footer>
                <div>
                    <p><a href="https://git.iu7.bmstu.ru/sgn3-prog/sgn3-prog-it-2022/it2022sgn-amaltheya/politikisto" className="transition">Amalteya</a> © BMSTU, SSH3; April, 2022 </p>
                </div>
            </footer>
        </React.Fragment>

    );
};

export default Party;
